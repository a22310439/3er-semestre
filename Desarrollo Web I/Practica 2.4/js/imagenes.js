var images = [
    'imagenes/img1.jpg',
    'imagenes/img2.jpg',
    'imagenes/img3.jpg',
    'imagenes/img4.jpg',
    'imagenes/img5.jpg',
    'imagenes/img6.jpg',
    'imagenes/img7.jpg',
    'imagenes/img8.jpg',
    'imagenes/img9.jpg',
    'imagenes/img10.jpg'
];

var currentIndex = 0;

function nextImage() {
    currentIndex++;
    if (currentIndex >= images.length) currentIndex = 0;
    document.getElementById('photo').src = images[currentIndex];
}

function previousImage() {
    currentIndex--;
    if (currentIndex < 0) currentIndex = images.length - 1;
    document.getElementById('photo').src = images[currentIndex];
}
