# pylint: disable=E1120
import streamlit as st
import pandas as pd
import numpy as np
import pydeck as pdk
import plotly.express as px

DATA_URL = ( "/Users/matiasmendez/Desktop/ProyectosPractica/ProyectoMapa/Motor_Vehicle_Collisions_-_Crashes.csv")

st.title("Motor Vehicles Collisions in New York City")
st.markdown("This is an app with Streamlit, puedes poner emoji")

#Funcion para importar data, numero de filas como parametro, parse_dates se hace una sola fecha con hora
#tambien se limpian los datos que se importan de una vez
#lo del @ hara que se ejecute una sola vez la functi y no cada vez que se inicie la app
@st.cache(persist=True)
def load_data(nrows):
    data = pd.read_csv(DATA_URL, nrows = nrows, parse_dates = [['CRASH_DATE','CRASH_TIME']])
    #esto es para no tener valores NA ni en latitud ni longitud, sino crashea app
    #son columnas y se necesta computar en inplace
    data.dropna( subset = ['LATITUDE','LONGITUDE'], inplace = True)
    #esta funcion vuelve todo string y despues todas las pone en minusculas
    lowercase = lambda x: str(x).lower()
    #esta es para renombrar las columnas simplemente del data frame lowercase
    data.rename(lowercase, axis = 'columns',inplace=True)
    #se renombrara una columna,a un nomre corto esto tiene formato de un diccionario
    data.rename(columns= {'crash_date_crash_time': 'date/time'}, inplace=True)
    return data
data = load_data(100000)
#agregamos este para el ultimo paso de la lsita interactiva
original_data = data


#MAPA interactivo

st.header("Where are the most people injured in NYC?")
#esta info es la que se vera en el mapa
#para hacerlo interactivo se pondran un slider con el min y max
#de las personas lastimadas en el data frame
injured_people = st.slider("Number of persons injured in car accidents",0,19)
#filtramos el data con la funcion query, "data" es la base de datos del DATA_URL
#injured_persons es una columna en data  y queremos asegurarnos que el valor de
#de la columna no exceda el de el slider, o sea que solo se eligiran las nrows
#cuya columna cumpla la columna y se regrsara la latitud y longitud para plotearlo
#en el mapa, van en minusculas porque con la funcion se puso todo en minusculas
#con dropna(how="any") estas diciendo que no se guardara en el data frame
#ninguna row de latitude y longitude que tenga na
st.map(data.query("injured_persons >= @injured_people")[["latitude","longitude"]].dropna(how="any"))

#Tabla interactiva con el slider
st.header("How many collisions occur during a given time of the day?")
#elegies la hora que quieres ver y se imprimen las horas con intervalos de 1

hour = st.slider("Hour to look at", 0, 23)
#se actualiza el data segun la hora seleccionada y se relaciona con la columnas
#de [date/time], que con .dt.hour ya se transformo a formato de horas
#entonces se mostrara el hour que indiques en el selectbox
data = data[data['date/time'].dt.hour == hour]

#---------------MAPA 3D interactivo
#Los valores de %i se cambairan siendo hour y hour+1 como se especifica con " %()" y tambien estas especificando
#que sera con marca de 24, para las 24 horas  recuerda que "hour" se define arriba con la selectbox
st.markdown("Vehicle collisions between %i:00 and %i:00" % (hour,(hour+1) % 24))

#los datos de midpoint se usaran en initial_view_state. pitch50 es el angulo de la vista, o sea mas abajjo
midpoint = (np.average(data['latitude']), np.average(data['longitude']))

#ahora para lograr nuestro mapa 3D vamos a descargar pydeck
#estanos creando una pydeck figure, importaremos un mapsytle  en map_style y con initial_view_state eligiremos
#situar nuestra vista del mapa en NYC, para eso calcularemos el punto medio de todos nuestras latitudes y longtiudes
#guardandolas en midpoint, es decir sacando el promedio de estas con la funcion de avarage de numpy
#con esto d eabajo no has graficado anda en el mapa, solo esta vacio
st.write(pdk.Deck(
    map_style = "mapbox://styles/mapbox/light-v9",
    initial_view_state = {
    "latitude" : midpoint[0],
    "longitude": midpoint[1],
    "zoom": 11,
    "pitch": 50,
    },
    #layers es una lista para plotear creo
    layers = [
        pdk.Layer(
    #con hexagon layer estas diciendo que se graficaran hexagonos en lugar de ciruculos
        "HexagonLayer",
    #data sera un subset del data que ya teniamos antes con 3 columnas
        data = data[['date/time', 'latitude', 'longitude']],
    #con get_postion se obtendra la posicion con latitude y longitude
        get_postion = ['longitude', 'latitude'],
        radius = 100,
        extruded = True,
        pickable =  True,
        elevation_scale = 4,
        elevation_range=[0,1000],
        ),
    ],
))

#----------Histogramas
st.subheader("Breakdown by minute between %i:00 and %i:00" % (hour, (hour +1)%24))
#filtraremos el data de nuevo, solo se mostrara el data de la columna date/time
#que cumpla con las condiciones de la variable hour controlada por el slider de arriba
#la info en la columna se tomo como un formato hora con la funcion dt.hour
#o sea solo se guardara en la variable filtered el data de UNA HORA
filtered = data[
    ( data['date/time'].dt.hour >= hour) & (data['date/time'].dt.hour < (hour+1))
]

#crearemos un Histogramas y le pasaremos nuestro filtered data de arriba
#que es el data de sólo UNA HORA, y lo vamos a mostrar por minuto
#iniciaremos con la posicion [0]
hist = np.histogram(filtered ['date/time'].dt.minute, bins = 60, range = (0,60))[0]

#creamos otro data frame para plotearlo creo, usando pandas
#se tienen dos columnas para minutos y otro de crashes usando hist
#o sea hist es como la frecuencia de los choques
chart_data = pd.DataFrame({'minute': range(60), 'crashes': hist})

#ploteamos chart_data como un graf de barras, donde en el eje x
#esta minute y en eje "y" esta la frecuencia dada por dataFrame hist
#lo de hover data es para que cuando pongas tu mouse sobre la barra, se muestren los minutos y crashes
fig = px.bar(chart_data, x = 'minute', y = 'crashes', hover_data=['minute','crashes'], height=400)
st.write(fig)

#crear una kista interactiva con pandas, en la que puedas seleccionar ver
#la info de ciertas columnas del DataFrame
st.header("Top 5 dangerous streets by affected type")
#agregamos selector
select = st.selectbox('affected type of people',['Pedestrians', 'Cyclists', 'Motorists'])

#se creo oringinal_data hasta arriba para filtrar info del tipo de personas afectadas y la calle
if select == 'Pedestrians':
    #si hay mas de 0 injured_pedestrians se monstrara injured_pedestrians y el nombre de la calle, luego con .sort_values se esta indicando que estaran en orden DESCENDIENTE y se dropearan NA y ssolo se mostrara el top 5 con :5
    st.write(original_data.query("injured_pedestrians >= 1")[["on_street_name", "injured_pedestrians"]].sort_values( by = ['injured_pedestrians'], ascending=False).dropna(how='any')[:5]  )
#se repetira lo mismo para las sig dos opciones del selector

elif select == 'Cyclists':
    #si hay mas de 0 injured_pedestrians se monstrara injured_pedestrians y el nombre de la calle, luego con .sort_values se esta indicando que estaran en orden DESCENDIENTE y se dropearan NA y ssolo se mostrara el top 5 con :5
    st.write(original_data.query("injured_cyclists >= 1")[["on_street_name", "injured_cyclists"]].sort_values( by = ['injured_cyclists'], ascending=False).dropna(how='any')[:5]  )

elif select == 'Motorists':
    #se hay mas de 0 injured_pedestrians se monstrara injured_pedestrians y el nombre de la calle, luego con .sort_values se esta indicando que estaran en orden DESCENDIENTE y se dropearan NA y ssolo se mostrara el top 5 con :5
    st.write(original_data.query("injured_motorists >= 1")[["on_street_name", "injured_motorists"]].sort_values( by = ['injured_motorists'], ascending=False).dropna(how='any')[:5]  )
#titulo
st.header('Raw Data')
#solo se mostrara si seleccionara la  palomita del checkbox
if st.checkbox("Show Raw Data", False):
    st.subheader("Raw Data")
    st.write(data)