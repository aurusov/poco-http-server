Один раз генерим Makefile
```
git clone git@github.com:aurusov/poco-http-server.git
cd poco-http-server
mkdir build
cd build
cmake ..
```

Для [Eclipse IDE for C/C++ Developers](http://www.eclipse.org/downloads/packages/) настраиваем один раз проект
- `Window - Preferences - Workspace - Save automatically before build` = `on`
- `File - Import - C/C++ - Existing Code as Makefile Project - Next`
- `Existing code location` = *путь к корню скаченных исходников*
- `Toolchain for Indexer Settings` = `Linux GCC`
- `Finish`
- `Project - Properties - C/C++ Build`
 - `Builder Settings - Build Directory` = `${workspace_loc:/poco-http-server/build}/`
 - `Behavior - Enable parallel build` = `on`
- `Project - Build All`
- `Run - Profile Configurations - poco-http-server Default - Main`
  - `C/C++ Applications` = *путь к корню скаченных исходников*`/build/poco-http-server`
  - `Disable auto build` = `on`
- `Run`

Проверим работу сервера из консоли
```
curl localhost:5849/ping -v
```
Ответ должен быть `200`, приблизительно таким
```
*   Trying 127.0.0.1...
* Connected to localhost (127.0.0.1) port 5849 (#0)
> GET /ping HTTP/1.1
> Host: localhost:5849
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 200 OK
< Date: Sun, 18 Sep 2016 14:08:12 GMT
< Connection: Close
< 
* Closing connection 0
```
