create table salary_raise(
    Instructor_ID number,
    Raise_date date,
    Raise_amt number);

set serveroutput on

declare
    cursor C(dname instructor.dept_name%TYPE) is 
    select * from instructor 
    where dept_name = dname;
    str instructor.dept_name%TYPE;
    instRow instructor%ROWTYPE;
begin
    str := '&DeptName';
    open C(str);
    loop
        fetch C 
        into instRow;
        exit when C%NOTFOUND;
        update instructor set salary = salary * 1.05 where ID = instRow.ID;
        insert into salary_raise values (instRow.ID,sysdate,instRow.salary*0.05);
    end loop;
    close C;
end;
/