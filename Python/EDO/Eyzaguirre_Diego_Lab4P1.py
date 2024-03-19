import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

#I
print("pregunta 1, I:")
def EDO(u,t):
    dudt= 500+np.exp(-t/2)-0.5*u #dejo toda la funcion al lado derecho así dejando u´ al lado izquierdo
    return dudt
u0=0
x= np.arange(0.0,600.0,0.1)
#ya teniendo armado el PVI, le doy los valores a R correspondientes
sol=odeint(EDO,u0,x)
print(f"la posición aproximada del nadador sería\n{sol[-1]}\nLa cual es aproximable a 1 kilometro")
print("pregunta 1, II:")
