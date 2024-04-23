// JavaScript for contact form submission
document.getElementById("contact-form").addEventListener("submit", function(event) {
    event.preventDefault();
    // Here you can add code to handle form submission, like sending an email or storing the message in a database
    alert("Message sent successfully!");
    this.reset();
  });