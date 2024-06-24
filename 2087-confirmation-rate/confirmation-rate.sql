SELECT SIG.user_id, COALESCE(ROUND((
    SELECT COUNT(action) 
    FROM Confirmations CON2
    WHERE CON2.user_id = SIG.user_id
    AND CON2.action = 'confirmed') / COUNT(action), 
    2), 0) AS confirmation_rate
FROM Signups SIG
LEFT JOIN Confirmations CON
ON SIG.user_id = CON.user_id
GROUP BY SIG.user_id