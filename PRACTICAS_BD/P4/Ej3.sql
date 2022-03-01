set serveroutput on;
DECLARE
    v_nombre votantes.nombrecompleto%type;
    v_correo votantes.email%type;
    mydni NUMBER := 30983712;
BEGIN
    select nombrecompleto, email
    into v_nombre, v_correo
    from votantes
    where dni=mydni;
    dbms_output.put_line(v_nombre||' con correo: '||v_correo);
END;
