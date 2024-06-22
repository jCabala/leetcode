SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM Project PRO LEFT JOIN Employee EMP
ON PRO.employee_id = EMP.employee_id
GROUP BY project_id