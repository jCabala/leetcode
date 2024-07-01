(SELECT 
    name AS results
FROM 
    Users U JOIN MovieRating M
    ON U.user_id = M.user_id
GROUP BY
    U.user_id
ORDER BY
    COUNT(U.user_id) DESC, name ASC
LIMIT 1
) UNION ALL (
SELECT 
    title AS result
FROM 
    Movies M JOIN MovieRating MR
    ON M.movie_id = MR.movie_id
WHERE
    MONTH(created_at) = 2
AND
    YEAR(created_at) = 2020
GROUP BY 
    M.movie_id
ORDER BY
    AVG(MR.rating) DESC, title ASC
LIMIT 1)