<div dir="rtl" lang="he">

# עץ הורים

ההורים שלכם תמיד אמרו לכם שאתם צאצאים של אדם מאד חשוב, אבל לא אמרו לכם מאיזה צד בדיוק.
כדי לברר את העניין, החלטתם לבנות לעצמכם עץ הורים.

כתבו מחלקה המייצגת עץ הורים של אדם אחד. 
המחלקה צריכה לתמוך בפעולות הבאות:

* addFather - הוספת אב למישהו שכבר נמצא בעץ.
* addMother - הוספת אם למישהו שכבר נמצא בעץ.
* relation - מקבלת שם של מישהו שנמצא בעץ, ומחזירה את היחס בינו לביניכם. למשל: father, mother, grandmother, great-grandfather, great-great-grandmother... אם הוא לא נמצא בעץ יש להחזיר unrelated.
* find - הפונקציה ההפוכה - מקבלת מחרוזת המציינת יחס כמו למעלה, ומחזירה את שם האדם מהעץ המקיים יחס זה.
* display - הצגת העץ, לצורך הדגמה וניפוי שגיאות. פורמט התצוגה - לבחירתכם.
* remove - מקבלת שם של מישהו שנמצא בעץ, ומוחקת אותו ואת כל ההורים שלו מהעץ.

אם יש כמה תשובות אפשריות - יש להחזיר אחת מהן שרירותית.
אם אין תשובה נכונה - יש לזרוק חריגה מתאימה.

כדי לראות איך המחלקה אמורה לעבוד, ראו בקובץ
[Demo.cpp](Demo.cpp)
המצורף.

בשלב א עליכם לכתוב את הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות קימפול:

<div dir='ltr'>

    make demo && ./demo
	make test && ./test

</div>

שימו לב:
יש לפתור את המטלה ע"י הוספת קבצים חדשים בלבד ולא ע"י שינוי קבצים קיימים.
הסיבה היא, שהבדקן האוטומטי מעתיק את הקבצים הקיימים על-גבי הקבצים שלכם,
ולכן כל שינוי שתבצעו לקבצים הקיימים לא ישפיע על הבדיקה האוטומטית.

</div> 
