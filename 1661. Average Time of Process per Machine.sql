SELECT machine_id
	,ROUND(SUM(CASE 
				WHEN activity_type = "end"
					THEN TIMESTAMP
				ELSE - TIMESTAMP
				END) / COUNT(DISTINCT process_id), 3) AS processing_time
FROM Activity
GROUP BY machine_id
