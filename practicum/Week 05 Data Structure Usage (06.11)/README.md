# СДП - Използване на структури от данни

## Задача 1
Имаме екип от програмисти реализиращи проект включващ работа в 3 направления - backend, web и mobile. Приемаме, че всеки програмист е специалист
в едно от трите направления и всяка задача се отнася само за едно направление. Помогнете на програмистите да планират своята работа за следващите 2 седмици при следните особености:
1. Първо се въвежда списък с програмистите. Всеки програмист има следните характеристики:
- Име
- Специализация (backend, web или mobile)
- Брой работни часове (между 20 и 80 за периода)
- Ниво (junior, middle, senior)
2. След това се въвежда списък със задачите. Задачите трябва да бъдат уникални (проверява се името на задачата). Всяка задача има следните
характеристики:
- Име
- Вид (backend, web или mobile)
- Време за изпълнение (попълва се времето, за което senior би изпълнил задачата)
- Приоритет (1, 2 и 3 като 1 е най-висок)
3. Програмата разпределя задачите на всеки един от програмистите като започва от най-приоритетните и отчита специализацията и оставащите работни часове на работника. Ако задачата не може да се изпълни от съответния програмист то се проверява дали следващия може. Ако няма програмист от съответната специализация, който има достатъчно часове, то задачата се прескача и се преминава към следващата до изчерпване на задачите или работните часове на програмистите. Да се приеме че един middle има нужда от 2 пъти повече време за изпълнение от един senior, а един junior 
2 пъти повече време за изпълнение от един middle.
4. Програмата разпечатва програмистите и задачите, които са им поставени по приоритет на задачите.
5. Програмата разпечатва оставащите задачи (ако има такива) по приоритет на задачите.

При реализацията да се използват подходящи структури от данни (списък, сет, стек, опашка), които са реализирани от вас. Целта не е да се намери най-оптималното решение, а да се направи разпределение на задачите!