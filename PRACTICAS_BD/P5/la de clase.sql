set serveroutput on;
declare
CURSOR dnis IS select dni from votantes order by dni desc;
dniAnterior votantes.dni%type;

BEGIN
    FOR unDni IN dnis LOOP
    if dniANterior is NULL THEN
        dniAnterior:=unDni.dni
    DBMS_OUTPUT.PUT_LINE(dniAnterior||' antes '||unDni.dni);
    dniAnterior :=unDni.dni;
    END IF;
END;