# pylint: disable=E1120
import streamlit as st
import pandas as pd
import numpy as np
import pydeck as pdk
import plotly.express as px



st.title("Covid Detector")
st.markdown("Datos del usuario")

st.header("Datos generales")

nombre = st.text_input("Nombre completo del usuario", '-')

edad = st.slider("Edad del usuario",0,130)



#------------sintomas---------
st.header("Síntomas")
#------enfermedades respiratorias-------

#agregamos selector
st.markdown('Enfermedad Respiratoria')
select = st.selectbox('Seleccione si padece alguna enfermedad respiratoria', ['Ninguna', 'Asma', 'Falta de aliento o dificultad respiratoria (disnea)', 'Congestión o secreción nasal','Resfriado', 'Enfermedad pulmonar', 'Otra'])

#agregamos selector
st.markdown('Enfermedades Gastrointestinales')
select = st.selectbox('Seleccione si padece alguna enfermedad gastrointestinal', ['Ninguna', 'Náuseas', 'Vómitos', 'Diarrea', 'Otra'])

#-------que si piquen otra les aparezca la opción de hacer un input
#se creo oringinal_data hasta arriba para filtrar info del tipo de personas afectadas y la calle
#if select == 'Pedestrians':
    #si hay mas de 0 injured_pedestrians se monstrara injured_pedestrians y el nombre de la calle, luego con .sort_values se esta indicando que estaran en orden DESCENDIENTE y se dropearan NA y ssolo se mostrara el top 5 con :5
    #st.write(original_data.query("injured_pedestrians >= 1")[["on_street_name", "injured_pedestrians"]].sort_values( by = ['injured_pedestrians'], ascending=False).dropna(how='any')[:5]  )
#se repetira lo mismo para las sig dos opciones del selector