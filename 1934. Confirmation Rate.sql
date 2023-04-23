SELECT Signups.user_id
	,round(avg(CASE 
				WHEN action = 'confirmed'
					THEN 1.00
				ELSE 0.00
				END), 2) AS confirmation_rate
FROM Signups
LEFT JOIN Confirmations ON Signups.user_id = Confirmations.user_id
GROUP BY Signups.user_id
