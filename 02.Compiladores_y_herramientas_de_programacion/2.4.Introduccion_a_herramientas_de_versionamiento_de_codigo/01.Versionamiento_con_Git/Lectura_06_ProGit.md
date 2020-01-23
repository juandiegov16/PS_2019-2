# Lectura 06

 Libro ProGit
 Capítulos 1, 2

 > Autor apuntes: Juan Diego Vallejo

## 1. Comenzando

### Sobre el control de versiones
* Es un sistema que guarda cambios a los archivos a través del tiempo, de forma
que luego se pueden rescatar versiones específicas.
* Permite revertir archivos (o un proyecto entero) a estados previos, comparar
cambios, ver quién modificó qué, etc.
#### Sistemas locales de control de versiones
* El "control de versiones" de mucha gente consiste en renombrar archivos o
copiarlos a otros directorios.

> Descripción gráfica

![](https://i.imgur.com/i7l3LQe.png)

#### Sistemas centralizados de control de versiones
* Otro problema que ha surgido es la necesidad de colaborar con desarrolladores
en otros sistemas.

> Descripción gráfica

![](https://i.imgur.com/DCDx1Vn.png)

* Ejemplos: CVS, Subversion, Perforce
* **Ventajas**:
  * Todos en el proyecto saben hasta cierto punto qué está haciendo el resto
  * Admins tienen control de quién puede hacer qué
  * Más fácil de administrar que bases de datos locales

* **Contras**:
  * Si el servidor centralizado se cae, todo se jode y nadie puede trabajar
  mientras el servidor esté muerto
  * Si el disco duro de la BD central se corrompe, ya fue :v

#### Sistemas distribuidos de control de versiones
* **Ejemplos**: Git, Mercurial, Bazaar, Darcs/
* Todo clon es una copia completa de todos los datos.

> Descripción gráfica

![](https://i.imgur.com/phOuvcM.png)

* Permite colaboración simultánea :)

### Corta historia de Git
(La dijo el profe cuando explicó el pedo de BitKeeper, pero aquí va de nuevo)
* 2002: Comenzó a existir BitKeeper
* 2005: La comunidad que desarrollaba Linux partió palito con la compañía
comercial detrás de BitKeeper, el cual dejó de ser gratis.
  * "Haré mi propio sistema de control de versiones con blackjack y mujerzuelas"  - Linus Torvalds
* 2005: Nace Git
### Lo básico de Git

#### Instantáneas, no diferencias
* Git piensa en sus datos como si fueran instantáneas de un sistema de archivos.
  * En cristiano: *Cada vez que se hace un commit, Git "toma una foto" de cómo
  está todo y guarda una referencia.*

![](https://i.imgur.com/yFMXpbs.png)
#### Casi toda operación es local
* Como toda la historia del proyecto está en el disco local, casi toda operación
tomará tanto tiempo como un chasquido de Thanos.
* Si no se tiene conexión a Internet, se puede trabajar (haciendo commmits)
y luego hacer push cuando tengas wifi. :)

#### Git tiene integridad
* Se le hace [checksum](https://www.techopedia.com/definition/1792/checksum) a TODO en Git antes que se almacene, de modo que es imposible
alterar un archivo o directorio sin que Git se entere. No es posible perder info
o sufrir corrompimiento de la misma sin que Git lo detecte.
* El mecanismo de seguridad utilizado se llama [SHA-1](https://en.wikipedia.org/wiki/SHA-1).

#### Git generalmente sólo añade datos
* Acción que se ejecute en Git agrega datos de la BD de Git, así que es MUY
difícil hacer algo... *irreversible*.
(Juandi, resiste la tentación de hacer una referencia a Monica Bellucci, POR FAVOR)

#### Los tres estados
* Commited: Datos guardados a salvo en base de datos local
* Modified: Archivo alterado pero no se ha hecho commit a la base de datos
* Staged: Archivo ha sido modificado y está señalado para formar parte del próximo commit.

![](https://i.imgur.com/DPd6KVM.png)

* Git directory: Donde Git guarda los metadatos y BD del proyecto.
* Working directory: Checkout de una versión del proyecto
* Staging area: Guarda información a utilizar en el próximo commit

### La línea de comando
* Es el único lugar donde se pueden correr TODOS los comandos de Git.
* La mayoría de GUIs implementan un subconjunto de los comandos por cuestiones
de simplicidad.

### Instalando Git

#### Instalar en Linux
```bash
sudo apt-get install git-all
```

### Configuración de la primera vez en Git
```
git config
```
#### Tu identidad
```
git config --global user.name "Nombre"
```
```
git config --global user.email nombre@mail.com
```
#### Tu editor
Se puede configurar el editor de texto por defecto que Git abrirá cuando necesita que escribas algo.
```
git config --global core.editor *nombre editor*
```

#### Tus ajustes
```
git config --list
```
### Obtener ayuda
```
git help <verbo>
git <verbo> --help
man git <verbo>
```

## 2. Elementos básicos de Git

### Consiguiendo un repositorio de Git

#### Inicializar un repositorio en un directorio existente
```
git init
```

#### Clonar un repositorio existente
```
git clone <direccion repositorio>
```

### Guardar cambios al repositorio
> El ciclo de vida de los estados de los archivos

![](https://i.imgur.com/2P2KD3b.png)
#### Revisar el estado de tus archivos
```
git status
```

#### Rastrear nuevos archivos
```
git add <nombre archivo>
```

#### Alistar archivos modificados (staging)
* Modificar un archivo ya rastreado y correr `git add <nombre archivo>`
(git add es multipropósito)

#### Estado corto
```
git status -s
```

#### Ignorar archivos
* Crear un archivo llamado `.gitignore` y escribir dentro de él los nombres
de los archivos que queremos que Git... ignore *Seinfeld Theme.mp3*

#### Ver cambios alistados y no alistados (staged/unstaged)
```
git diff
```

```
git diff --staged
```

#### Hacer commit a los cambios
```
git commit
```

```
git commit -m "Descripción commit"
```

#### Saltar el staging area
```
git commit -a
```
#### Remover archivos
```
git rm <nombre archivo>
```

### Ver el historial de commits
```
git log
```
#### Limitar la salida del registro
>Ejemplo: Commits hechos en las últimas 2 semanas

```
git log --since=2.weeks
```

### Revirtiendo cosas
```
git commit --amend
```
#### "Unstaging" a un archivo en estado "staged"
```
git reset HEAD <nombre archivo>
```
#### Descartar cambios a un archivo modificado
```
git checkout -- <nombre archivo>
```
### Trabajar con remotos

#### Mostrar tus remotos
```
git remote -v
```
#### Añadir repositorios remotos
```
git remote add <nombre corto> <url>
```
#### Hacer fetch/pull a tus remotos
```
git fetch [nombre-remoto]
```
#### Hacer push a tus remotos
```
git push origin master
```
#### Inspeccionar un remoto
```
git remote show origin
```
#### Remover y renombrar remotos
```
git remote rename [nombre-viejo] [nombre-nuevo]
```
