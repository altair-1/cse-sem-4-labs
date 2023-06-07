set serveroutput on

declare
    cursor C is 
    select * from teaches;
    N number;
    instrname instructor.name%TYPE;
    courseRow course%ROWTYPE;
    sectionRow section%ROWTYPE;
begin
    for I IN C
    loop
        begin
            select count(*) 
            into N from takes 
            group by course_id, sec_id, semester, year 
 	    having course_id = I.course_id and sec_id = I.sec_id and semester = I.semester and year = I.year;
        end;
        select name 
        into instrname from instructor where ID = I.ID;
        select * into sectionRow from section where course_id = I.course_id and sec_id = I.sec_id and semester = I.semester and year = I.year;
        select * into courseRow from course where course_id = I.course_id;
        dbms_output.put_line('course ID: ' || I.course_id || ' title: ' || courseRow.title || ' dept name: ' || courseRow.dept_name || ' credits: ' || courseRow.credits || 
        ' instructor name: ' || instrname || ' building: ' || sectionRow.building || ' room number: ' || sectionRow.room_number || ' time slot id: ' || sectionRow.time_slot_id || ' total students enrolled: ' || N);
    end loop;
end;
/