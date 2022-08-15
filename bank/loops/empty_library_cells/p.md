## مساله

پس از عبور از بحران كرونا، دانشگاه‌ها تلاش مي‌كنند تا شرايط را براي برگزاري كلاس‌هاي حضوري آماده كنند.
از آنجا كه كتاب‌خانه دانشگاه، مدت زياديست كه خالي بوده،‌ براي آماده‌سازي نياز به تمهيداتي دارد.
در مرحله اول، نياز است كه قفسه‌هاي كتاب‌خانه را مرتب كنيم.
در اين كتاب‌خانه، قفسه‌ها به صورت يك جدول n\*n مي‌باشند، كه در هر‌يك از خانه‌هاي اين جدول، در صورت وجود كتاب، مقدار 1، و در غير اين صورت، مقدار 0 قرار دارد.
مسئول كتاب‌خانه از ما خواسته برنامه‌اي بنويسيم، كه با گرفتن اطلاعات يك قفسه، تعداد سطر‌هايي را كه در آن بيش از 1 خانه خالي وجود دارد، چاپ كنيم.

ورودي:
در خط اول تنها عدد نا‌منفي n را داريم. با شرط:
0 <= n < 200
در هر n خط بعدي،‌ n عدد (0 يا 1) -كه با يك space از يكديگر جدا‌ شده‌اند- آمده‌اند كه مشخص مي‌كنند، هر خانه از قفسه، پر است يا خير.

خروجي:
تنها در يك خط، تعداد سطر‌هايي كه تعداد ‌0ها در آن بيشتر از يك عدد بوده را چاپ كنيد.

## ورودی نمونه 1

```sh
3
0 1 1
1 1 1
0 1 1
```

## خروجی نمونه 1

```sh
0
```

## ورودی نمونه 2

```sh
5
1 1 1 1 0
1 1 0 1 1
0 1 0 0 1
1 0 1 1 0
1 1 1 1 1
```

## خروجی نمونه 2

```sh
2
```