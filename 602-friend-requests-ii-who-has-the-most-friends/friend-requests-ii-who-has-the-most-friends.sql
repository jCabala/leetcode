SELECT
    id, SUM(num) AS num
FROM
    (
        SELECT 
            requester_id AS id, COUNT(accepter_id) as num
        FROM 
            RequestAccepted
        GROUP BY
            id
        UNION ALL
        SELECT 
            accepter_id AS id, COUNT(requester_id) as num
        FROM 
            RequestAccepted
        GROUP BY
            id
    ) RN
GROUP BY id
ORDER BY num DESC
LIMIT 1
