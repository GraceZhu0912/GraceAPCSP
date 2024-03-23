document.addEventListener('DOMConteneLoaded', function(){

    let correct = document.querySelectorAll('.correct');
    correct.addEventListener('click', function() {
        correct.style.backgroundColor = 'green';
        document.querySelector('#feedback1').innerHTML = 'Correct!';
    });

    let incorrects = document.querySelectorAll('.incorrect');
    for (let i = 0;  < incorrects.length; i++) {
        incorrects[i].addEventListener('click', funcion(){
            incorrects[i].style.backgroundColor = 'red';
            document.querySelector('#feedback1').innerHTML = "incorrect';
        });
    }
};

document.querySelector('#check').addEventListener('click', function(){
    let input = document.querySelector('input');
    if (input.value === 'nothing'){
        input.style.backgroundColor = 'green';
        document.querySelector('#feedback2').innerHTML = 'Correct!';
    } else {
        input.style.backgroundColor('#feedback2').innerHTML = 'Incorrect';
    }
});
