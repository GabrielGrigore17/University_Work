
--CREATE DATABASE dbSecretariat2122
--ON
--PRIMARY ( NAME = Secretariat21,
--FILENAME = 'D:\Google Classroom\Anul 3\DB\LAB3\Secretariat_1.mdf ' ,
--SIZE = 10,
--MAXSIZE = 40,
--FILEGROWTH = 2 )
--LOG ON
--( NAME = Secretariat21_log,
--FILENAME = 'D:\Google Classroom\Anul 3\DB\LAB3\Secretariat21_log1.ldf' ,
--SIZE = 10,
--MAXSIZE = 20,
--FILEGROWTH = 2 )
--GO

--USE dbSecretariat2122
--GO

--CREATE TABLE tblStudent(
--NrLeg char (8) PRIMARY KEY CLUSTERED,
--CNP varchar(13) UNIQUE,
--NumeStudent varchar(40) NOT NULL,
--InitialaStudent varchar (6),
--PrenumeStudent varchar(40) NOT NULL,
--Sex char (1) CHECK (Sex IN ('M','F')) DEFAULT ('M'),
--DataNastere datetime,
--GrupaSinge varchar (3),
--StareCivila char (1) CHECK (StareCivila IN ('C', 'D', 'M', 'N', 'V')),
--SituatiaMilitara char (1) CHECK (SituatiaMilitara IN ('I','N')),
--Grupa char (5) CHECK (Grupa LIKE '10%')
--)

--CREATE TABLE tblTelefonStud(
--NrLeg char(8) NOT NULL,
--NrTelefon varchar(10),
--Interior varchar(4),
--Observatii varchar(30),
--CONSTRAINT conTel_FK
--	FOREIGN KEY (NrLeg) REFERENCES tblStudent (NrLeg)
--	ON DELETE CASCADE ON UPDATE CASCADE
--)

--CREATE TABLE tblMaterie(
--ID_Materie char(6) PRIMARY KEY CLUSTERED,
--NumeMaterie varchar (30) NOT NULL,
--Semestrul varchar(2) NOT NULL,
--OreCurs tinyint,
--OreSeminar tinyint,
--OreLaborator tinyint,
--OreProiect tinyint,
--TipMaterie varchar(1) CHECK (TipMaterie IN ('F','N','0'))
--DEFAULT ('N'),
--FormaExaminare varchar (3) CHECK (FormaExaminare IN ('E','CFN', 'CN'))
--DEFAULT('E'),
--Credit tinyint CHECK (Credit BETWEEN 1 AND 6)
--)

--CREATE TABLE tblStudiaza(
--Nrleg char(8) NOT NULL REFERENCES tblStudent (NrLeg)
--ON DELETE CASCADE ON UPDATE CASCADE,
--ID_Materie char (6) NOT NULL REFERENCES tblMaterie (ID_Materie)
--ON DELETE CASCADE ON UPDATE CASCADE
--)

--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('102345','1840612163219','Popa', 'M', 'Dan','A', 'N','I')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('102346', '2841123163219', 'Andreescu', 'Gh.', 'Ana', 'B', 'N','N')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('102347','1830131164318', 'Andreescu','Gh.', 'Marin', 'B','C','I')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('102348', '1840331164318', 'Pappa', 'Gh.', 'Mircea-Dan','A','C','I')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('104738', '2810430146318', 'Papa', 'F1.', 'Maria', 'A', 'N', 'N')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('104567', '1821205163733', 'Popa', 'Gh.', 'Marin', 'B', 'N','I')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('103248', '1830321161818', 'Popescu', 'Gh.', 'Marin','A','C','I')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('109999','2830331164318', 'Danescu', 'Gh.', 'Maria', 'B','C','N')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('108765', '1821124164318', 'Popa','I.', 'Ion','A', 'N','I')
--INSERT INTO tblStudent
--(NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('102793', '2810730147218', 'Popescu', 'M.', 'Dana','A', 'N', 'N')

--SELECT * FROM tblStudent

--INSERT INTO tblMaterie VALUES ('M001', 'Analiza matematica 1','1',3,2,0,0,'N','E', 4)
--INSERT INTO tblMaterie VALUES ('M002', 'Analiza matematica 2','1',3,2,0,0,'N','E', 4)
--INSERT INTO tblMaterie VALUES ('M003', 'Algebra','1',3,2,0,0,'N','E',4)
--INSERT INTO tblMaterie VALUES ('P001', 'Programare', '1',3,2,0,0, 'N','E', 6)
--INSERT INTO tblMaterie VALUES ('M004', 'Analiza matematica 2', '2',3,2,0,0, 'N', 'E', 4)
--INSERT INTO tblMaterie VALUES ('P002', 'Tehnici de programare','2',3,2,0,0, 'N','E',6)
--INSERT INTO tblMaterie VALUES ('M005', 'Analiza numerica','3',3,2,0,0, 'N','E', 4)
--INSERT INTO tblMaterie VALUES ('7001','Fizica','3',3,2,0,0,'N','E', 4)
--INSERT INTO tblMaterie VALUES ('T001', 'Bazele electrotehnicii 1','3',3,2,0,0, 'N','E', 4)
--INSERT INTO tblMaterie VALUES ('T002', 'Bazele electrotehnicii 2', '4',3,2,0,0,'F', 'CN', 2)

--SELECT * FROM tblMaterie

--INSERT INTO tblStudent (NrLeg, CNP, NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('103248', '1820822163218', 'Popa', 'Gh.', 'Grigore', 'A', 'N', 'I')

--INSERT INTO tblStudent (NrLeg,CNP,NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('1109248', '18208222163218', 'Popa', 'Gh.', 'Grigore', 'A', 'N', 'I')

--INSERT INTO tblStudent (NrLeg,CNP,NumeStudent, InitialaStudent, PrenumeStudent, GrupaSinge, StareCivila, SituatiaMilitara)
--VALUES ('1109248', '1820822163218', 'Popa', 'Gh.', 'Grigore', 'A', 'N', 'M')

--INSERT INTO tblStudiaza VALUES ('104567', 'MOO1')
--INSERT INTO tblStudiaza VALUES ('104567', 'MOO3')
--INSERT INTO tblStudiaza VALUES ('104567', 'POO1')
--INSERT INTO tblStudiaza VALUES ('104568', 'MOO1')

--SELECT * FROM tblStudiaza

--UPDATE tblStudent SET Grupa='10205'--UPDATE tblStudent SET Grupa=NULL--UPDATE tblStudent SET Grupa=10205 WHERE NrLeg='102345'
--UPDATE tblStudent SET Grupa=10206 WHERE NrLeg='102346'
--UPDATE tblStudent SET Grupa=10205 WHERE NrLeg='102341'
--UPDATE tblStudent SET Grupa=10205 WHERE NrLeg='702348'
--UPDATE tbLStudent SET Grupa=10105 WHERE NrLeg='104738'
--UPDATE tblStudent SET Grupa=10205 WHERE NrLeg='10456i'
--UPDATE tblStudent SET Grupa=10105 WHERE NrLeg='103248'
--UPDATE tblStudent SET Grupa=10205 WHERE NrLeg='109999'
--UPDATE tblStudent SET Grupa=10205 WHERE NrLeg='108765'
--UPDATE tblStudent SET Grupa=10205 WHERE NrLeg='102193'--TRUNCATE TABLE tblStudent--DELETE FROM tblStudent--DROP DATABASE dbSecretariat2122