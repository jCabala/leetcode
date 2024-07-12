SELECT
    DP.name AS department,
    EM.name AS employee,
    salary
FROM
    Employee EM
JOIN
    Department DP
ON
    EM.departmentId = DP.id
WHERE
    (
        SELECT
            COUNT(DISTINCT salary)
        FROM
            Employee
        WHERE 
            departmentId = EM.departmentId
        AND
            salary >= EM.salary
    ) <= 3
