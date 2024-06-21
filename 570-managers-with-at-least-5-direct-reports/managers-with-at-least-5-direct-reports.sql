SELECT MAN.name
FROM Employee MAN, Employee EMP
WHERE EMP.managerID = MAN.id
GROUP BY MAN.id
HAVING COUNT(EMP.id) >= 5