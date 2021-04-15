set serveroutput on;
DECLARE
    CURSOR a IS SELECT presidente from partidos;                                                    /*Cursor llamado a que se posiciona en la columna presidente de la tabla partidos*/
BEGIN
    FOR nombre IN a LOOP                                                                            /*Para una variable nombre en el cursor a, haz el bucle*/
        IF substr(nombre.presidente, instr(nombre.presidente,' ',1,1)-1,1) = 'o' THEN               /*Si la primera palabra termina en o continua*/
            IF substr(nombre.presidente, instr(nombre.presidente,' ',1,2)-1,1) = 'o' THEN           /*Si la segunda palabra termina en o continua*/
                IF substr(nombre.presidente, instr(nombre.presidente,' ',1,3)-1,1) = 'o' THEN       /*Si la tercera palabra termina en o continua*/
                    dbms_output.put_line(nombre.presidente);                                        /*Imprimimos por pantalla el resultado*/
                END IF;
            END IF;
        END IF;        
    END LOOP

END;
