SELECT * 
FROM Cinema
WHERE id % 2 = 1 && description != "boring"
ORDER BY rating DESC