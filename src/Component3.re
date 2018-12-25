type state = {inputValue: string};

let valueFromEvent = e: string => ReactEvent.Form.target(e)##value;

let component = ReasonReact.reducerComponent("Component 3");

let make = (_children, ~parentChoice) => {
  ...component,
  initialState: () => "",
  reducer: (newText, _text) => ReasonReact.Update(newText),
  render: self =>
    <div className="mt3">
      <input
        placeholder="enter something"
        onChange={e => self.send(valueFromEvent(e))}
      />
      <ol>
        <li> {ReasonReact.string("One")} </li>
        <li> {ReasonReact.string("Two")} </li>
        <li> {ReasonReact.string("Three")} </li>
        <li> {ReasonReact.string("Four")} </li>
        <li> {ReasonReact.string(parentChoice)} </li>
        <li> {ReasonReact.string(self.state)} </li>
      </ol>
    </div>,
};
