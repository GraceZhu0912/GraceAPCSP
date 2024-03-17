let counter = localStorage.getItem('counter') || 0;

// Function to increment the counter and update the display
function incrementCounter() {
    counter++;
    // Update the display
    document.getElementById('counterDisplay').innerText = counter;
    // Store the updated counter value in localStorage
    localStorage.setItem('counter', counter);
}

// Function to initialize the counter display when the page loads
window.onload = function() {
    document.getElementById('counterDisplay').innerText = counter;
};

var cells = document.querySelectorAll('#editableTable td');
cells.forEach(function(cell) {
    cell.addEventListener('click', function() {
        this.setAttribute('contenteditable', 'true');
    });
});
