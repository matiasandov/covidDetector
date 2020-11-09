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

st.markdown('¿Padece **diabetes**?')
diabetes = st.selectbox('Conteste sí o no', ['Sí', 'No'])

st.markdown('¿Padece **hipertensión**?')
hipertension = st.selectbox('Conteste sí o no.', ['Sí', 'No'])




#------------sintomas---------
st.header("Síntomas")
#------enfermedades respiratorias-------

#agregamos selector
st.markdown('Enfermedad Respiratoria')
eRespiratorias = st.selectbox('Seleccione si padece alguna enfermedad respiratoria', ['Ninguna', 'Asma', 'Falta de aliento o dificultad respiratoria (disnea)', 'Congestión o secreción nasal','Resfriado', 'Enfermedad pulmonar', 'Otra'])

if eRespiratorias == 'Otra':
    eRespiratorias = st.text_input('Escriba a continuación la enfermedad respiratoria ', '-')

#agregamos selector
st.markdown('Enfermedades Gastrointestinales')
eGastro = st.selectbox('Seleccione si padece alguna enfermedad gastrointestinal', ['Ninguna', 'Náuseas', 'Vómitos', 'Diarrea', 'Otra'])

if eGastro == 'Otra':
    eGastro = st.text_input('Escriba a continuación la enfermedad gastrointestinal', '-')

#-------que si piquen otra les aparezca la opción de hacer un input
#se creo oringinal_data hasta arriba para filtrar info del tipo de personas afectadas y la calle
#if select == 'Pedestrians':
    #si hay mas de 0 injured_pedestrians se monstrara injured_pedestrians y el nombre de la calle, luego con .sort_values se esta indicando que estaran en orden DESCENDIENTE y se dropearan NA y ssolo se mostrara el top 5 con :5
    #st.write(original_data.query("injured_pedestrians >= 1")[["on_street_name", "injured_pedestrians"]].sort_values( by = ['injured_pedestrians'], ascending=False).dropna(how='any')[:5]  )
#se repetira lo mismo para las sig dos opciones del selector

st.markdown('¿Padece **pérdida de olfato**?')
olfato = st.selectbox('Pérdida de olfato.', ['Sí', 'No'])

st.markdown('¿Padece **hipertensión**?')
fiebre = st.selectbox('Hipertensión', ['Sí', 'No'])