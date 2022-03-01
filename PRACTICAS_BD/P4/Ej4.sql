set serveroutput on;
DECLARE
    v_nombre votantes.nombrecompleto%type;
    v_dni NUMBER:=30983712;
BEGIN
    select substr(nombrecompleto,instr(nombrecompleto,' ')) into v_nombre
    from votantes
    where dni=mydni;
    dbms_output.put_line('Pepe'||v_nombre);

END;
