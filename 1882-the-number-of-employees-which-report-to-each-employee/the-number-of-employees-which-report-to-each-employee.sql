SELECT
    MAN.employee_id,
    MAN.name,
    COUNT(REP.employee_id) AS reports_count,
    ROUND(AVG(REP.age), 0) AS average_age
FROM Employees MAN 
INNER JOIN Employees REP
ON MAN.employee_id = REP.reports_to
GROUP BY MAN.employee_id
ORDER BY MAN.employee_id
