let canvas = document.getElementById('canvas');
let ctx = canvas.getContext('2d');

canvas.style.backgroundColor = 'black';
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

let x = 0;
let y = 0;
let fontSize = 25;
let cw = canvas.width / fontSize;
let ch = canvas.height / fontSize;

let chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789#;:%$@';
let fallingChars = []; // Array to store falling characters
let maxChars = 500 * (cw / 100);
let colors = ['cyan', 'magenta', 'gold', 'white', 'green', 'lime', 'red'];
let colorIndex = Math.floor(Math.random() * colors.length);

window.addEventListener('resize', () => {
	canvas.width = window.innerWidth;
	canvas.height = window.innerHeight;
	cw = canvas.width / fontSize;
	ch = canvas.height / fontSize;
	maxChars = 500 * (cw / 100);
	fallingChars = [];
})

class FallingChar {
	constructor(x, y, speed) {
		this.x = x;
		this.y = y;
		this.speed = speed;
	}

	draw() {
		ctx.font = fontSize + 'px monospace';
		ctx.fillStyle = colors[colorIndex];
		ctx.fillText(chars[Math.floor(Math.random() * chars.length)], this.x, this.y);
	}
}

let update = () => { 
	ctx.fillStyle = 'rgba(0, 0, 0, 0.05)';
	ctx.fillRect(0, 0, cw * fontSize, ch * fontSize);
	let speed = Math.floor(Math.random() * 5) + 10;
	x = Math.floor(Math.random() * cw) * fontSize;
	if (fallingChars.length < maxChars) {
		fallingChars.push(new FallingChar(x, y, speed));
	}
	
	fallingChars.forEach(char => { 
		char.y += char.speed;
		if (char.y > ch * fontSize && Math.random() > 0.5) char.y = 0;
		char.draw();
	});
};

setInterval(update, 1000 / 30);
