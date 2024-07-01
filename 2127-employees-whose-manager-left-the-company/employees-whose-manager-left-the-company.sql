SELECT employee_id
FROM Employees EMP
WHERE salary < 30000
AND manager_id IS NOT NULL
AND (
    SELECT employee_id
    FROM Employees
    WHERE employee_id = EMP.manager_id) IS NULL
ORDER BY employee_id