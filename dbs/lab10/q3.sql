set serveroutput on
create or replace
procedure course_popular(d_name varchar) is
cursor C(d course.dept_name%TYPE) is 
select course_id from course where dept_name = d;
courseID course.course_id%TYPE;
m integer;
counter integer;
begin
    m:= -1;
    for I in C(d_name)
    loop
        begin
            select count(*) 
	    into counter 
  	    from takes 
	    group by course_id 
	    having course_id = I.course_id;
        exception
            when no_data_found then 
		counter := 0;
        end;
        if counter > m then
            m := counter;
            courseID := I.course_id;
        end if;
    end loop;
    dbms_output.put_line('most popular course of ' || d_name || ' is ' || courseID);
end;
/

declare
    cursor C is 
    select distinct dept_name from course;
begin
    for I in C
    loop
        course_popular(I.dept_name);
    end loop;
end;
/