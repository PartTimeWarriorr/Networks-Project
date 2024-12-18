# Multi-threaded quicksort project (using pthread)
Проект за курса по Мрежово програмиране 2024/2025

## How to Build 
### On Ubuntu
```
 make
```
Creates two executables: server.out and client.out.
### On Windows
```
не знам
```

## Usage
Run both server.out and client.out in separate terminals. 
Client.out чака въвеждане на следните команди:

>За излизане от програмата:
```c
exit
```
>За сортиране на масив от данни, използвайки <брой_нишки> нишки, също връща резултата и информацията за протичане на процеса на клиента:
```c
sort <брой_нишки> <големина_на_масива> <числа_разделени_със_whitespace>
```

## Основни стъпки при разработване на проекта
1. Проучване на quicksort алгоритми, начини за имплементиране. 
2. Имплементиране на singlethreaded quicksort.
3. Проучване на начини за имплементиране на mutlithreaded алгоритми. 
4. Имплементиране на thread pool, queue (за пазене на тасковете).
5. Имплементиране на функцията, която нишките ще изпълняват.

https://github.com/PartTimeWarriorr/Networks-Project/blob/e421e4d491bcd178c3d6b8880f4f9263edf06a4c/m-quicksort.c#L86-L119

6. Добавяне на променливи за брой на таскове и брой на активни нишки, както и такава за статус на сортирането (done) 
(не се сетих как иначе ще стане ясно, че сортирането е приключило). Имплементиране на loop-a на главната функция, проверяваща кога сортирането е приключило.

https://github.com/PartTimeWarriorr/Networks-Project/blob/e421e4d491bcd178c3d6b8880f4f9263edf06a4c/m-quicksort.c#L37-L45

7. Проучване на начини за имплементиране на client-server модел на C.
8. Имплементиране на server и client.
9. Добавяне на utils.c за parse-ване на входните команди на клиента.
10. Makefile
