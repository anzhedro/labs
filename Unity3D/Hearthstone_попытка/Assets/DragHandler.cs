using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.EventSystems;
public class DragHandler : MonoBehaviour, IBeginDragHandler, IDragHandler, IEndDragHandler
{
    public static GameObject itemBeingDragged;
    Vector3 startPosition;
    Transform startParent;
    Transform canvas;

    public void OnBeginDrag(PointerEventData eventData)
    {
        itemBeingDragged = gameObject;
        startPosition = transform.position;
        startParent = transform.parent;
        GetComponent<CanvasGroup>().blocksRaycasts = false;
        canvas = GameObject.FindGameObjectWithTag("UI Canvas").transform;
        transform.parent = canvas;
    }

    public void OnDrag(PointerEventData eventData)
    {
        transform.position = Input.mousePosition;
    }

    public void OnEndDrag(PointerEventData eventData)
    {
        Debug.Log(transform.parent + " == " + canvas);
        itemBeingDragged = null;
        GetComponent<CanvasGroup>().blocksRaycasts = true;
        if (transform.parent == canvas)
        {
            transform.position = startPosition;
        }
    }
}
//public class DragHandler : MonoBehaviour, IBeginDragHandler, IDragHandler, IEndDragHandler
//{
//    public static GameObject item;    // i changed itembeigdraged to item.


//    Transform startParent;
//    Vector3 startPosition;
//    bool start = true;
//    //Sprite sprite;

//    public void OnBeginDrag(PointerEventData eventData)
//    {
//        item = gameObject;
//        startPosition = transform.position;
//        startParent = transform.parent;

//        GetComponent<CanvasGroup>().blocksRaycasts = false;
//        item.GetComponent<LayoutElement>().ignoreLayout = true;
//        item.transform.SetParent(item.transform.parent.parent);
//    }


//    public void OnDrag(PointerEventData eventData)
//    {

//        transform.position = Input.mousePosition;
//    }

//    public void OnEndDrag(PointerEventData eventData)
//    {
//        item = null;

//        if (transform.parent == startParent)
//        {
//            transform.position = startPosition;
//        }
//        GetComponent<CanvasGroup>().blocksRaycasts = true;

//        item.GetComponent<LayoutElement>().ignoreLayout = false;
//    }

//}
