select nombre 
from localidades
where numerohabitantes >
    (select numerohabitantes
    from localidades
    where idlocalidad=
        (select localidad
        from votantes
        where fechanacimiento=
            (select min(fechanacimiento)
            from votantes
            where fechanacimiento>
                (select min(fechanacimiento)
                from votantes)
            )
        )
    )