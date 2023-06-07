set serveroutput ON

declare
    cursor C(cid teaches.course_id%TYPE) is select distinct id from teaches where course_id = cid;
    instrName instructor.name%TYPE;
    cid teaches.course_id%TYPE;
begin
    cid := '&CourseID';
    for I in C(cid)
    loop
        select name 
	into instrName 
	from instructor 
	where ID = I.ID;
        dbms_output.put_line('ID: ' || I.ID || ' name: ' || instrName);
    end loop;
end;
/