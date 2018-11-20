resultados : runOde runPde graficas_ode graficas_pde resultados.tex
	pdflatex resultados.tex	
runOde: ode.cpp 
	g++ ode.cpp
	./a.out >> ode45.dat	
runPde: pde.cpp 
	g++ pde.cpp
	./a.out >> pde_datosA.dat
graficas_ode:graficasOde.py
	python graficasOde.py
graficas_pde:graficasOde.py
	python graficasPde.py
