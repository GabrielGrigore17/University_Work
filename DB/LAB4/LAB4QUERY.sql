--SELECT NumeStudent, InitialaStudent, PrenumeStudent, Grupa
--FROM dbo. tbIStudent

--SELECT NumeStudent, InitialaStudent, PrenumeStudent, Grupa
--FROM dbo.tblStudent
--ORDER BY Grupa , NumeStudent , PrenumeStudent , InitialaStudent

--SELECT Grupa, NumeStudent+' '+Initia1aStudent +' '+PrenumeStudent AS Student
--FROM dbo.tblStudent
--ORDER BY Grupa , NumeStudent, PrenumeStudent, InitialaStudent


--SELECT NumeStudent+ ' ' +InitiaIaStudent+ ' ' +PrenumeStudent AS [Studenti grupa 20051]
--FROM dbo.tblStudent
--WHERE Grupa=' 10205'
--ORDER BY NumeStudent, PrenumeStudent, InitialaStudent

--SELECT NumeStudent+' '+ InitiaIaStudent+ ' ' +PrenumeStudent AS [Student i grupa 2005], DataNastere
--FROM dbo.tblStudent
--WHERE Grupa='10205'
--ORDER BY NumeStudent, PrenumeStudent,InitialaStudent

--SELECT NumeStudent+"+InitialaStudent+"+PrenumeStudent 
--AS [Studenti grupa 2005],CONVERT(char(10),DataNastere,3) 
--AS [data nasterii] 
--FROM dbo.tblStudent 
--WHERE Grupa-'10205' 
--ORDER BY NumeStudent,PrenumeStudent,InitialaStudent 

--SELECT NumeStudent+"+InitialaStudent+"+PrenumeStudent 
--AS (Studenti grupa 2005],YEAR (DataNastere) 
--AS [an nastere] 
--FROM dbo.tb1Student 
--WHERE Grupa='10205' 
--ORDER BY NumeStudent,PrenumeStudent,InitialaStudent 

--SELECT NumeStudent+"+InitialaStudent+"+PrenumeStudent 
--AS [Studenti grupa 2005],DATEDIFF (YY,DataNastere,GETDATE()) 
--AS varsta 
--FROM dbo.tblStudent 
--WHERE Grupa='10205' 
--ORDER BY NumeStudent,PrenumeStudent,InitialaStudent 

--SELECT Grupa, COUNT(NrLeg) 
--AS Inumar studenti] 
--FROM dbo.tb1Student 
--GROUP BY Grupa 

--SELECT Grupa, AVG(DataNastere) 
--FROM dbo.tblStudent 
--GROUP BY Grupa 

--SELECT Grupa, AVG(CONVERT(integer,DataNastere)) 
--FROM dbo.tblStudent 
--GROUP BY Grupe 

--SELECT Grupa, CONVERT(smalldatetime,AVG(CONVERT(integer,DataNastere))) 
--AS [data nastere medie] 
--FROM dbo.tb1Student 
--GROUP BY Grupa 

--SELECT Grupa, CONVERT(char(10),CONVERT(smalldatetime,AVG(CONVERT(integer,DataNastere)),103),103) 
--AS [data nastere media] 
--FROM dbo.tblStudent 
--GROUP BY Grupa 

--SELECT Grupa, COUNT(NrLeg) AS [numar studenti grupe anul II] 
--FROM dbo.tb1Student 
--WHERE Grupa LIKE '102%' 
--GROUP BY Grupa 

--SELECT Grupa, COUNT(NrLeg) AS [numar studenti grupe anul II] 
--FROM dbo.tb1Student 
--GROUP BY Grupa 
--HAVING Grupa LIKE '102%' 

--INSERT INTO tb1Student 
--VALUES('1032991,'1810730641183','Predescui,'Al.','Dinu.,W, CONVERT(smalldatetime,'30/07/1981',103),'A','C','I','10206') 
--INSERT INTO tblStudent VALUES('1033991,'1810730623183','Predescu','Al.','Mihais,'M', 
--CONVERT(smalldatetime,'30/07/1981',103),'A','C','I','10206') 

--SELECT TOP 20PERCENT NumeStudent+"+InitialaStudent+"+PrenumeStudent 
--AS [cei mai in varsta 20% studenti], CONVERT(char(10),DataNastere,103)
--AS [data nasterii] 
--FROM dbo.tblStudent 
--ORDER BY DataNastere, NumeStudent,PrenumeStudent,InitialaStudent 

--SELECT TOP 20PERCENT WITH TIES NumeStudent4"+InitialaStudent+' 1+prenumeStudent 
--AS [cel mai tanar student], CONVERT(char(10),DataNastere,103)
--AS [data nasterii] FROM dbo.tb1Student 
--ORDER BY DataNastere 

--SELECT NumeStudent+"+InitialaStudent+"+PrenumeStudent 
--AS Ice' mai tanar student],CONVERT(char(10),DataNastere,103)
--AS [data nasterii] FROM (SELECT TOP 20 PERCENT WITH TIES * 
--FROM dbo.tb1Student ORDER BY DataNastere) 
--AS tb1Stud ORDER BY DataNastere, NumeStudent,PrenumeStudent,InitialaStudent 

--SELECT NumeStudent+"+InitialaStudent+"+prenumeStudent 
--AS [Studenti], CONVERT(char(10),DataNastere,103)AS [data nasterii] 
--FROM dbo.tb1Student W
--HERE DataNastere>=CONVERT(smalldatetime, '01/01/1982',103)AND DataNastere<=CONVERT(smalldatetime, '31/12/1983',103) 
--ORDER BY DataNastere,NumeStudent,prenumeStudent,InitialaStudent 

--SELECT NumeStudent4"+lnitialaStudent+"+PrenumeStudent 
--AS iStudentill CONVERT(char(10),DataNastere,103)AS [data nasterii] 
--FROM dbo.tb1Student 
--WHERE DataNastere BETWEEN CONVERT(smalldatetime, '01/01/1982',103)AND CONVERT(smalldatetime, '31/12/1983',103) 
--ORDER BY DataNastere,NumeStudent,PrenumeStudent,InitialaStude:.: 

--SELECT NumeStudent+' ' = InitialaStudent+' '+PrenumeStudent AS [Studenti],
--CONVERT (char (10), DataNastere,103)AS [data nasterii]
--FROM dbo.tblStudent
--WHERE YEAR(DataNastere)IN (1982,1983)
--ORDER BY DataNastere, NumeStudent, PrenumeStudent, InitialaStudent