SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(order_number) = (
		SELECT MAX(count_res)
		FROM (
			SELECT COUNT(order_number) AS count_res
			FROM Orders
			GROUP BY customer_number
			) AS max_subquery
		);
