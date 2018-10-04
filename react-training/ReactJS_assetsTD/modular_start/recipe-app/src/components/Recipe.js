// import IngredientsList
import IngredientsList from './IngredientsList'
// import Instructions
import Instructions from './Instructions'

// declare the Recipe module
const Recipe = ({ name, ingredients, steps}) =>
    <section id={name.toLowerCase().replace(/ /g, '-')}>
      <h1>{name}</h1>
      <IngredientsList list={ingredients} />
      <Instructions title="Cooking Instructions" steps={steps} />
    </section>

// export default Recipe
export default Recipe
