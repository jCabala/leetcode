# Write your MySQL query statement below
SELECT ps.machine_id, ROUND(AVG(pe.timestamp - ps.timestamp), 3) AS processing_time
FROM Activity ps, Activity pe
WHERE ps.process_id = pe.process_id
AND ps.machine_id = pe.machine_id
AND ps.activity_type = 'start'
AND pe.activity_type = 'end'
GROUP BY ps.machine_id