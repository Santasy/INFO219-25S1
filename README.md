En este repositorio se encuentra el material de INFO219 - Algorítmica Computacional.

Para facilitar su trabajo, les recomiendo:
- Usar VSCode o VSCodium.
- Instalar [Competitive Programming Helper (CPH)](https://github.com/agrawal-d/cph/tree/main) como exensión de VSCode. Para VSCodium necesitará el [archivo .vsix](https://www.vsixhub.com/vsix/9996/) se la extensión.
- Instalar [Competitive Companion](https://github.com/jmerle/competitive-companion#readme) como extensión de navegador (Firefox o Google Chrome).
- Usar el [makefile](./clases/makefile) de la carpeta clases, te ayuda a compilar y testear con archivos de forma genérica. Para utilizarlo en otras carpetas, ubiquese en su carpeta destino, y llame a makefile con la ruta hacia este makefile:
```
cd clase\ 5/
make -f ../makefile file=F_Ardent_Flames.cpp prob=p1
make -f ../makefile run prob=p1
```

Sebastián P. Cáceres
2025, Primer Semestre.