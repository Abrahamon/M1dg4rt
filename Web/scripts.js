var c = document.getElementById("MapaCanvas");
var ctx = c.getContext("2d");
var cd = document.getElementById("DiosesCanvas");
var ctxDioses = cd.getContext("2d");

var img = document.getElementById("mapa");
var imgPelea = document.getElementById("mapaPelea");
var lenin = document.getElementById("Lenin");
var Mauricio = document.getElementById("Mauricio");
var fabian = document.getElementById("Fabian");
var Abraham = document.getElementById("Abraham");
imgPelea.width=100;
ctx.drawImage(img,0,0);


var i = 0;
var j = 0;
var k = 0;
var h = 0;

var x1 = 30;
var y1 = 0;

var x2 = 540;
var y2 = 0;

var x3 = 30;
var y3 = 330;

var x4 = 530;
var y4 = 330;

var cont;
var points = [1,2,45,4,8,4,5,5]; //array con la cantidad de miembros
ctx.fillStyle= "#c15236";
var app = angular.module('myApp', []);

app.controller('TableData', function($scope, $http, $interval) {

    $scope.Pelea = 0;               //Si esta en 1, hay pelea, no se pintan los Individuos
    $scope.FightAvailable;          //La lógica muestra que hay una pelea disponible (Leido desde JSON)
    $scope.PuebloPelea1 ;           //Pueblo para pelear A
    $scope.PuebloPelea2 ;           //Pueblo para pelear B
    $scope.StartFightCounter=0;     //Contador para iniciar la pelea (Permite que los ejercitos tomen posición)
    $scope.loadFightMapCounter = 0; //Contador para la carga del mapa.
    $scope.contadorDeOpacidad = 0;  //Contador para la animación de aparición del mapa.
    $scope.LockFight=false;         //Establece si está transcurriendo o no una batalla.
    $scope.BatallaCerrada = false;  //Establece si ya la batalla fue cerrada.
    $scope.NombrePapa = "Padre";
    $scope.NombrePapa = "Padre";
    $scope.NombrePapa = "Padre";
    $scope.names;
    $scope.pueblo;
    $scope.NombreDeIndividuo;
    $scope.Attack;
    $scope.Speed;
    $scope.Defence;
    $scope.Intelligence;
    $scope.Magic;
    $scope.Energy;
    $scope.Blot;
    $scope.RunesPower;
    $scope.Cantidad1 = 1;
    $scope.Cantidad2 = 1;
    $scope.Cantidad3 = 1;
    $scope.Cantidad4 = 1;

    $scope.FightGods = "false";
    $scope.GodsSet = false;
    $scope.Dios1 = "Zeus";
    $scope.Dios2 = "Hades";
    $scope.Dios3 = "Poseidón";
    $scope.Dios4 = "Afrodita";
    $scope.GodsInfo;





    $scope.caracteristicas = function(nombre,attack,speed,defence,intelligence,magic,energy,blot,runespower){
        $scope.NombreDeIndividuo = nombre;
        $scope.Attack = attack;
        $scope.Speed = speed;
        $scope.Defence = defence;
        $scope.Intelligence = intelligence;
        $scope.Magic = magic;
        $scope.Energy = energy;
        $scope.Blot = blot;
        $scope.RunesPower = runespower;

    }
    $scope.onsearch = function(name){
        $scope.pueblo = name;
    }
    ///
    ///Metodo para abrir imagen de pelea
    $scope.alacarga = function(){
        $scope.Pelea = 1;
        $scope.loadFightMapCounter = 0;
            $interval(function () {

                if($scope.loadFightMapCounter < 17) { //Para evitar que el mapa se siga pintado una vez que ya finalizó.
                    ctx.globalAlpha = $scope.contadorDeOpacidad;
                    $scope.contadorDeOpacidad += 0.05;
                    ctx.drawImage(imgPelea, 5, 5, 695, 494);
                    $scope.loadFightMapCounter += 1;
                    $scope.Pelea = 1;
                }

            }, 100)

    }
    ///Metodo para cerrar imagen de pelea
    $scope.cerrarBatalla = function(){
        if($scope.BatallaCerrada == false){
            $scope.Pelea = 0;
            ctx.clearRect ( 0 , 0 , 695, 494 );
            $scope.BatallaCerrada = true;
        }

    }
   $scope.cargar = function(nombre){/////////////////////////esta es para los bicho
        $http.get("JSON/"+nombre+".json").success(function (response) {$scope.nombres = response.records;});

    }
    $scope.Pintar = function(){
        ctx.drawImage(img,0,0);
    }
    $scope.mover1 = function(){$interval(function(){x1 += 5; y1 += 2; if($scope.StartFightCounter >= 25){x1 =30;y1 = 0;}},2000,5)}
    $scope.mover2 = function(){$interval(function(){x2 -= 5; y2 += 2; if($scope.StartFightCounter >= 25){x2 =540;y2 = 0;}},2000,5)}
    $scope.mover3 = function(){$interval(function(){x3 += 5; y3 -= 2; if($scope.StartFightCounter >= 25){x3 =30;y3 = 330;}},2000,5)}
    $scope.mover4 = function(){$interval(function(){x4 -= 5; y4 -= 2 ; if($scope.StartFightCounter >= 25){x4 =530;y4 = 330;}},2000,5)}



    $interval(function(){
        $http.get("JSON/time.json").success(function (response) {$scope.TotalTime = response.records;});
    },500)

    $interval(function(){
        $http.get("JSON/GodsWar.json").success(function (response) {
            $scope.FightGods = response.records[0].War;
            if($scope.FightGods == "true"){
                $interval(function(){ctxDioses.drawImage(lenin,50,100,140,200);},100,1)
                $interval(function(){ctxDioses.drawImage(Mauricio,210,100,140,200);},100,1)
                $interval(function(){ctxDioses.drawImage(fabian,370,100,140,200);},100,1)
                $interval(function(){ctxDioses.drawImage(Abraham,530,100,140,200);},100,1)
                if($scope.GodsSet == false){



                    x1 =10;
                    y1 = 310;

                    x2 = 190;
                    y2 = 310;

                    x3 = 370;
                    y3 = 310;

                    x4 = 550;
                    y4 = 310;
                    $scope.GodsSet = true;
                }

            }
            if($scope.FightGods == "false"){
                cd.width = cd.width;
                x1 = 30;
                y1 = 0;

                x2 = 540;
                y2 = 0;

                x3 = 30;
                y3 = 330;

                x4 = 530;
                y4 = 330;
                $scope.GodsSet = false;
            }
        });
    },1000)


    $interval(function(){
        if($scope.FightGods == "true"){

        }

    },500)


    $interval(function(){
        $http.get("JSON/puebloDwarves.json").success(function (response) {$scope.name1 = response.records;$scope.Cantidad1 = response.records[0].Miembros;});
        $http.get("JSON/puebloElves.json").success(function (response) {$scope.name2 = response.records;$scope.Cantidad2 = response.records[0].Miembros;});
        $http.get("JSON/puebloGiants.json").success(function (response) {$scope.name3 = response.records;$scope.Cantidad3 = response.records[0].Miembros;});
        $http.get("JSON/puebloDarkElves.json").success(function (response) {$scope.name4 = response.records;$scope.Cantidad4 = response.records[0].Miembros;});
        $http.get("JSON/GodsWar.json").success(function (response) {$scope.GodsInfo = response.records;});

    },500)

    $interval(function(){
        $http.get("JSON/fight.json").success(function (response) {
            $scope.FightAvailable=response.records[0].FightAvailable;
            
            if($scope.FightAvailable == "false"){
                $scope.cerrarBatalla();
                $scope.StartFightCounter = 0;
                $scope.LockFight = false;
                $scope.contadorDeOpacidad=0;

            }
            if($scope.FightAvailable == "true"){ //Si hay una pelea disponible, se procede a mover a los grupos correspondientes
                $scope.BatallaCerrada = false;
                if($scope.StartFightCounter >= 25){
                    if( $scope.LockFight == false) {
                        $scope.LockFight = true;//Fija la pelea, para que no se muevan nuevamente los grupos.
                        $scope.alacarga(); //Carga la imagen del mapa de Pelea.
                    }
                }
                if( $scope.LockFight == false) {
                    $http.get("JSON/fight.json").success(function (response) {
                        $scope.guerra = response.records;
                        $scope.PuebloPelea1 = response.records[0].Pueblo1;
                        $scope.PuebloPelea2 = response.records[0].Pueblo2;

                        if ($scope.PuebloPelea1 == 1) {$scope.mover1();$scope.PuebloPelea1 = 1;}
                        if ($scope.PuebloPelea1 == 2) {$scope.mover2();$scope.PuebloPelea1 = 2;}
                        if ($scope.PuebloPelea1 == 3) {$scope.mover3();$scope.PuebloPelea1 = 3;}
                        if ($scope.PuebloPelea1 == 4) {$scope.mover4();$scope.PuebloPelea1 = 4;}

                        if ($scope.PuebloPelea2 == 1) {$scope.mover1();$scope.PuebloPelea2 = 1;}
                        if ($scope.PuebloPelea2 == 2) {$scope.mover2();$scope.PuebloPelea2 = 2;}
                        if ($scope.PuebloPelea2 == 3) {$scope.mover3();$scope.PuebloPelea1 = 3;}
                        if ($scope.PuebloPelea2 == 4) {$scope.mover4();$scope.PuebloPelea1 = 4;}

                        $scope.StartFightCounter++;

                    });
                }
            }
        });

    },500)


    $interval(function(){
        if($scope.Pelea == 0) {
            ctx.clearRect ( 0 , 0 , 695, 494 );
            $scope.Pintar();

            /////////////////////////////primer pueblo////////////////////////////////////////////////////////////////
            $interval(function () {//funcion que se repite y va dibujando los puntitos
                if($scope.Pelea == 0) {
                    ctx.strokeStyle = "#c15236";
                    i = x1 + Math.floor((Math.random() * 160) + 1);// aqui cambio el treinta por k y a ajao igual
                    j = y1 + Math.floor((Math.random() * 160) + 1);
                    ctx.beginPath();
                    ctx.strokeRect(i, j, 2, 2);
                    ctx.fill();
                }
            }, 10, $scope.Cantidad1)

            ////////////////////////////////segundo pueblo////////////////////////////////////////////////////////////////
            $interval(function () {//funcion que se repite y va dibujando los puntitos
                if($scope.Pelea == 0) {
                    ctx.strokeStyle = "#1AFF00";
                    i = x2 + Math.floor((Math.random() * 160) + 1);
                    j = y2 + Math.floor((Math.random() * 160) + 1);
                    ctx.beginPath();
                    ctx.strokeRect(i, j, 2, 2);
                    ctx.fill();
                }
            }, 10, $scope.Cantidad2)


            ////////////////////////////////tercer pueblo////////////////////////////////////////////////////////////////

            $interval(function () {//funcion que se repite y va dibujando los puntitos
                if($scope.Pelea == 0) {
                    ctx.fillStyle = "#1500FF";
                    i = x3 + Math.floor((Math.random() * 160) + 1);
                    j = y3 + Math.floor((Math.random() * 160) + 1);
                    ctx.beginPath();
                    ctx.arc(i, j, 2, 5, 6, true);
                    ctx.fill();
                }
            }, 10, $scope.Cantidad3)


            ////////////////////////////////Cuarto pueblo////////////////////////////////////////////////////////////////
            $interval(function () {//funcion que se repite y va dibujando los puntitos
                if($scope.Pelea == 0) {
                    ctx.fillStyle = "#FFE600";
                    i = x4 + Math.floor((Math.random() * 160) + 1);
                    j = y4 + Math.floor((Math.random() * 160) + 1);
                    ctx.beginPath();
                    ctx.arc(i, j, 2, 5, 6, true);
                    ctx.fill();
                }
            }, 10, $scope.Cantidad4)

        }

    },3000)









});


//////////////////////////////////***********************************************////////////////////////////////



// Change the selector if needed
var $table = $('table.scroll'),
    $bodyCells = $table.find('tbody tr:first').children(),
    colWidth;

// Adjust the width of thead cells when window resizes
$(window).resize(function() {
    // Get the tbody columns width array
    colWidth = $bodyCells.map(function() {
        return $(this).width();
    }).get();

    // Set the width of thead columns
    $table.find('thead tr').children().each(function(i, v) {
        $(v).width(colWidth[i]);
    });
}).resize(); // Trigger resize handler