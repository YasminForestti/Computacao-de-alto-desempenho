PROGRAM matriz_vetor_multiplication
   IMPLICIT NONE
    INTEGER :: num,i, j, ROWS, COLS, inverso, unit, ierr, arg_count,max
    CHARACTER(len = 40) :: max_char
    CHARACTER(len = 40) :: inverso_char
    REAL :: start_time, end_time, time_elapsed
    REAL, DIMENSION(:,:), ALLOCATABLE :: A
    REAL, DIMENSION(:), ALLOCATABLE :: b, x
    CHARACTER(len=30) :: filename = "dados_fortran_0.csv"

    arg_count = command_argument_count()

    if (arg_count < 2) then
        write(*,*) "Usage: ./program max inverso"
        stop
    end if

    call get_command_argument(1,max_char)
    call get_command_argument(2,inverso_char)

    read(max_char,*) max
    read(inverso_char,*) inverso    
    
    do num = 1, max, 10
        ROWS = num
        COLS = num

    ALLOCATE(A(ROWS,COLS))
    ALLOCATE(b(ROWS))
    ALLOCATE(x(COLS))
 
    CALL RANDOM_NUMBER(A)
    CALL RANDOM_NUMBER(b)
    x = 0.0


    ! Inicia a contagem de tempo
    CALL CPU_TIME(start_time)

    IF (inverso == 1) THEN
        do i = 1, ROWS
            do j = 1, COLS
                b(i) = b(i) + A(i,j) * x(j)
            end do
        end do
    ELSE
        do j = 1, COLS
            do i = 1, ROWS
                b(i) = b(i) + A(i,j) * x(j)
            end do
        end do
    END IF

    CALL CPU_TIME(end_time)
    time_elapsed = end_time - start_time

    
    open(newunit=unit, file=trim(filename), status='old', access='append', iostat=ierr)
    
    write(unit, "(i0,';',i0,';',f5.2,';',i0)") ROWS, COLS, time_elapsed, inverso
    close(unit)
    DEALLOCATE(A)
    DEALLOCATE(b)
    DEALLOCATE(x)

    end do
END PROGRAM matriz_vetor_multiplication
