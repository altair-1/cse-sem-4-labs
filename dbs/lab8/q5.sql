alter table StudentTable add LetterGrade VARCHAR2(2);

set SERVEROUTPUT ON

declare
    G StudentTable.GPA%TYPE;
    N number;
    I number;
begin
    select count(*) 
    into N from StudentTable;
    I := 1;
    while I <= N
    loop
        select GPA
        into G
        from StudentTable
        where RollNo = I;
        if G > 0 and G <= 4 then
            update StudentTable set LetterGrade = 'F' where RollNo = I;
        elsif G > 4 and G <= 5 then
            update StudentTable set LetterGrade = 'E' where RollNo = I;
        elsif G > 5 and G <= 6 then
            update StudentTable set LetterGrade = 'D' where RollNo = I;
        elsif G > 6 and G <= 7 then
            update StudentTable set LetterGrade = 'C' where RollNo = I;
        elsif G > 7 and G <= 8 then
            update StudentTable set LetterGrade = 'B' where RollNo = I;
        elsif G > 8 and G <= 9 then
            update StudentTable set LetterGrade = 'A' where RollNo = I;
        elsif G > 9 and G <= 10 then
            update StudentTable set LetterGrade = 'A+' where RollNo = I;
        end if;
        I := I + 1;
    end loop;
end;
/