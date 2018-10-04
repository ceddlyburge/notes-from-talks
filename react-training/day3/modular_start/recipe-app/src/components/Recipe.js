// import IngredientsList
import IngredientsList from './IngredientsList'

// import Instructions
import Instructions from './Instructions'

// declare the Recipe module
const Recipe = ({name, ingredients, steps}) =>
    <section className="recipe" id={name.toLowerCase().replace(/ /g, '-')} >
    <h1>{name}</h1>
    <IngredientsList ingredients={ingredients} />
    <Instructions steps={steps} />
    </section>
    // export default Recipe
export default Recipe