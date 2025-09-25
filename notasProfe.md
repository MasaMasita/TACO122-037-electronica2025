# Nota para el profesor

Para trabajar con submódulos:

- Crear carpeta para recibir cada bitácora e ir a ella

```
cd bitacoras
```

- Para agregar submódulo

```
git submodule add <enlace-repo-bitácora> bitacora1   
```

- Si clonas un repositorio que tiene submódulos es necesario incluirlos luego de clonarlos

```
git submodule init
git submodule update
```

- Para que Git incluya automáticamente los submódulos en ciertos comandos sin que tengas que poner la opción --recurse-submodules cada vez

```
git config submodule.recurse true
```



- Utilizar este comando para hacer un pull que incluya los submódulos

```
git pull --recurse-submodules && git submodule update --remote --merge --recursive
```

- Se puede configurar un alias para que haga todo esto más rápido

```
git config --global alias.pullall '!git pull --recurse-submodules && git submodule update --remote --merge --recursive'
```

## Cosas que deberíamos considerar para un manifiesto del curso

1. Lo raro es que las cosas funcionen como queremos
2. Aprender consiste en fallar
3. La vida es tan difícil como graciosa
4. Mi trabajo como profesor es en parte enseñarles a lidiar
5. Su trabajo como estudiantes es en parte comunicar lo que les pase
6. El mundo existe porque se nos resiste. La resistencia no se opone, conduce
7. Escuchar y observar son formas de conocimiento
8. Todo está en transformación. Ningún proyecto se termina
9. Trabajar 



