// declare the Instructions module
const Instructions = ({steps}) =>
    <section className="instructions">
        {steps.map((step, i) =>
            <p key={i}>{step}</p>
        )}
    </section>
// export default Instructions
export default Instructions